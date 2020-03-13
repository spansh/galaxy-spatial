#define RAPIDJSON_SSE42

#include "rapidjson/document.h"
#include "rapidjson/error/en.h"
#include "rapidjson/istreamwrapper.h"
#include <iostream>
#include <experimental/filesystem>
#include <string>
#include <experimental/optional>

#include <boost/iostreams/device/file.hpp>
#include <boost/iostreams/filtering_stream.hpp>
#include <boost/iostreams/filter/bzip2.hpp>

#include "GalaxyHash.hpp"
#include "BodyTypesHash.hpp"
#include "BodySubtypesHash.hpp"
#include "GalaxyStructs.hpp"

#include <spatialindex/capi/sidx_api.h>
#include <spatialindex/capi/sidx_impl.h>
#include <spatialindex/capi/sidx_config.h>

#define REPORT_SIZE 100000
#define CLOSE_STAR 100
#define LIMIT 0

using namespace std;
using namespace std::experimental;
using namespace std::chrono;
using namespace rapidjson;
using namespace SpatialIndex;

class Handler {
    protected:
        unsigned long int level;
        ParseSection currentSection;
        ParseSection nextSection;
        ParseTypes nextType;
        void *nextField;
    public: 
        bool isFinishedSystem;
        bool isFinishedBody;
        System system;
        Body body;
        
        Handler() {
            this->level = 0;
            this->nextField = NULL;
        }
        bool Null() {
            return true;
        }
        bool Bool(bool b) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::boolean) {
                    *(bool*)this->nextField = b;
                } else {
                    cerr << "Bool value was not recognised " << b << " Type: " << (unsigned int) this->nextType << " should have been " << (unsigned int) ParseTypes::boolean << endl;
                    throw "Bool value was not recognised";
                }
            }
            return true;
        }
        bool Int(int value) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::integer) {
                    *(unsigned long int*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::optional_integer) {
                    *(optional<unsigned long int>*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::real) {
                    *(double*)this->nextField = (double) value;
                } else if (this->nextType == ParseTypes::optional_real) {
                    *(optional<double>*)this->nextField = (double) value;
                } else {
                    cerr << (string) __func__ << "value was not recognised " << value << " Type: " << (unsigned int) this->nextType << endl;
                    throw (string) __func__ + " value was not recognised";
                }
            }
            return true;
        }
        bool Uint(unsigned value) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::integer) {
                    *(unsigned long int*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::optional_integer) {
                    *(optional<unsigned long int>*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::real) {
                    *(double*)this->nextField = (double) value;
                } else if (this->nextType == ParseTypes::optional_real) {
                    *(optional<double>*)this->nextField = (double) value;
                } else {
                    cerr << (string) __func__ << "value was not recognised " << value << " Type: " << (unsigned int) this->nextType << endl;
                    throw (string) __func__ + " value was not recognised";
                }
            }
            return true;
        }
        bool Int64(int64_t value) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::integer) {
                    *(unsigned long int*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::optional_integer) {
                    *(optional<unsigned long int>*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::real) {
                    *(double*)this->nextField = (double) value;
                } else if (this->nextType == ParseTypes::optional_real) {
                    *(optional<double>*)this->nextField = (double) value;
                } else {
                    cerr << (string) __func__ << "value was not recognised " << value << " Type: " << (unsigned int) this->nextType << endl;
                    throw (string) __func__ + " value was not recognised";
                }
            }
            return true;
        }
        bool Uint64(uint64_t value) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::integer) {
                    *(unsigned long int*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::optional_integer) {
                    *(optional<unsigned long int>*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::real) {
                    *(double*)this->nextField = (double) value;
                } else if (this->nextType == ParseTypes::optional_real) {
                    *(optional<double>*)this->nextField = (double) value;
                } else {
                    cerr << (string) __func__ << "value was not recognised " << value << " Type: " << (unsigned int) this->nextType << endl;
                    throw (string) __func__ + " value was not recognised";
                }
            }
            return true;
        }
        bool Double(double value) {
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::integer) {
                    *(unsigned long int*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::optional_integer) {
                    *(optional<unsigned long int>*)this->nextField = (unsigned long int) value;
                } else if (this->nextType == ParseTypes::real) {
                    *(double*)this->nextField = (double) value;
                } else if (this->nextType == ParseTypes::optional_real) {
                    *(optional<double>*)this->nextField = (double) value;
                } else {
                    cerr << (string) __func__ << "value was not recognised " << value << " Type: " << (unsigned int) this->nextType << endl;
                    throw (string) __func__ + " value was not recognised";
                }
            }
            return true;
        }
        bool RawNumber(const char* str, SizeType length, bool copy) {
            (void) str;
            (void) copy;
            (void) length;
            return true;
        }
        bool String(const char* str, SizeType length, bool copy) {
            (void) copy;
            (void) length;
            if (this->nextField != NULL) {
                if (this->nextType == ParseTypes::scalar) {
                    *(string*)this->nextField = str;
                } else {
                    cerr << "String value was not recognised " << str << " Type: " << (unsigned int) this->nextType << endl;
                    throw "String value was not recognised";
                }
            }
            return true;
        }
        bool Key(const char* str, SizeType length, bool copy) {
            (void)copy;

            const KeyLookup* lookup = GalaxyKey::Lookup(str,length);

            if (lookup != NULL) {
                if (lookup->within_section == this->currentSection) {
                    this->nextType = lookup->next_type;
                    if (lookup->current_section != ParseSection::same) {
                        this->currentSection = lookup->current_section;
                        this->nextSection = lookup->next_section;
                    }

                    if (lookup->offset >= 0) {
                        switch (this->currentSection) {
                            case ParseSection::bodies:
                                this->nextField = ((char *)(&this->body)) + lookup->offset;
                                break;
                            default:
                                this->nextField = ((char *)(&this->system)) + lookup->offset;
                                break;
                        }
                    }
                } else {
                    this->nextField = NULL;
                }
            } else {
                this->nextField = NULL;
            }

            return true;
        }
        bool StartObject() {
            this->level++;
            if (this->level == 2) {
                this->currentSection = ParseSection::system;
                this->system = {};
                this->isFinishedSystem = false;
            } else if (this->level == 4) {
                if (this->currentSection == ParseSection::bodies) {
                    this->body = {};
                }
            }
            return true;
        }
        bool EndObject(SizeType memberCount) {
            (void) memberCount;
            this->level--;
            if (this->level == 1) {
                this->isFinishedSystem = true;
            } else if (this->level == 3) {
                if (this->currentSection == ParseSection::bodies) {
                    // cerr << this->system.id64 << " has body subtype " << this->body.subtype << endl;

                    const BodySubtypeHash* lookup = BodySubtypeKey::Lookup(this->body.subtype.c_str(),this->body.subtype.length());
                    if (lookup != NULL) {
                        if (this->body.isMainStar) {
                            if (lookup->subtype == BodySubtypes::neutron_star) {
                                this->system.isNeutron = true;
                            } else if (lookup->isScoopable) {
                                this->system.isScoopable = true;
                            }
                        } else {
                            if (this->body.distanceToArrival < CLOSE_STAR) {
                                if (lookup->isScoopable) {
                                    this->system.isScoopable = true;
                                }
                                if (lookup->subtype == BodySubtypes::neutron_star) {
                                    this->system.isNeutron = true;
                                }
                            }
                        }
                    }
                }
            }

            if (this->level == 2) {
                if (this->nextSection != ParseSection::same) {
                    // cerr << "Parse section is now " << (unsigned int) this->nextSection << " from " << (unsigned int) this->currentSection << endl;
                    this->currentSection = this->nextSection;
                    this->nextSection = ParseSection::same;
                }
            }
            return true;
        }
        bool StartArray() {
            this->level++;
            return true;
        }
        bool EndArray(SizeType elementCount) {
            (void) elementCount;
            this->level--;
            if (this->level == 2) {
                if (this->nextSection != ParseSection::same) {
                    // cerr << "Parse section is now " << (unsigned int) this->nextSection << " from " << (unsigned int) this->currentSection << endl;
                    this->currentSection = this->nextSection;
                    this->nextSection = ParseSection::same;
                }
            }
            return true;
        }
};

class MyDataStream : public IDataStream {
protected:
    string filename;
    boost::iostreams::filtering_istream inputStream;
    Handler handler;
    Reader reader;
    IStreamWrapper* stream;
    high_resolution_clock::time_point t1,t2,t3;
    unsigned long int count;
public:
    MyDataStream(string filename) : m_pNext(NULL) {
        this->filename = filename;

        inputStream.push(boost::iostreams::bzip2_decompressor());
        inputStream.push(boost::iostreams::file_source(filename));

        this->stream = new IStreamWrapper(inputStream);

        this->reader.IterativeParseInit();
        this->count = 0;

        this->t1 = high_resolution_clock::now();
        this->t3 = this->t1;

        this->readNextEntry();
    }
    ~MyDataStream() override
    {
        if (this->m_pNext != NULL) delete this->m_pNext;
    }

    IData* getNext() override
    {
        if (this->m_pNext == NULL) return NULL;

        RTree::Data* ret = this->m_pNext;
        this->m_pNext = NULL;
        this->readNextEntry();
        return ret;
    }

    bool hasNext() override
    {
        return (this->m_pNext != NULL);
    }

    uint32_t size() override
    {
        throw Tools::NotSupportedException("Operation not supported.");
    }

    void rewind() override
    {
        throw Tools::NotSupportedException("Operation not supported.");
    }

    void readNextEntry()
    {
        if (LIMIT > 0 && this->count > LIMIT) {
            this->m_pNext = NULL;
            return;
        }
        while (!this->reader.IterativeParseComplete() && !this->reader.HasParseError()) {
            this->reader.template IterativeParseNext<kParseDefaultFlags>(*stream, handler);
            if (this->handler.isFinishedSystem) {
                this->count++;
                if (this->count % REPORT_SIZE == 0) {
                    this->t2 = high_resolution_clock::now();
                    duration<double> total_time_span = duration_cast<duration<double>>(this->t2 - this->t1);
                    duration<double> last_time_span = duration_cast<duration<double>>(this->t2 - this->t3);
                    cerr << "Finished system " << this->count << ": " << this->handler.system.id64 << "(" << this->handler.system.x << "," << this->handler.system.y << "," << this->handler.system.z << ") (";
                    if (this->handler.system.isNeutron) {
                        cerr << "neutron/";
                    } else {
                        cerr << "no neutron/";
                    }
                    if (this->handler.system.isScoopable) {
                        cerr << "is scoopable/";
                    } else {
                        cerr << "not scoopable/";
                    }
                    cerr << ") in " << last_time_span.count() << " seconds at " << (REPORT_SIZE / last_time_span.count()) << "/sec, total " << total_time_span.count() << " seconds at " << (count / total_time_span.count()) << "/sec" << endl;

                    this->t3 = this->t2;
                }

                double coords[] = {this->handler.system.x,this->handler.system.y,this->handler.system.z};
                Region region(coords, coords, 3);
                this->m_pNext = new RTree::Data(sizeof(System), reinterpret_cast<uint8_t*>(&this->handler.system), region, this->handler.system.id64);
                return;
            }
        }
        if (reader.HasParseError()) {
            cerr << "Parse error in " <<
                filename << " [" <<
                GetParseError_En(reader.GetParseErrorCode()) <<
                "] offset [" <<
                reader.GetErrorOffset() <<
                "]" <<
                endl;
            throw "Parse error";
        }
    
    }

    RTree::Data* m_pNext;
};


int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        exit(1);
    }
    
    char* pszVersion = SIDX_Version();
    cerr << "libspatialindex version: " << pszVersion << endl;
    free(pszVersion);

    Tools::PropertySet* ps = GetDefaults();
    Tools::Variant var;
    var.m_varType = Tools::VT_ULONG;
    var.m_val.ulVal = RT_RTree;
    ps->setProperty("IndexType", var);

    var.m_varType = Tools::VT_ULONG;
    var.m_val.ulVal = 3;
    ps->setProperty("Dimension", var);

    var.m_varType = Tools::VT_PCHAR;
    var.m_val.pcVal = const_cast<char*>("spatial_index_2");
    ps->setProperty("FileName", var);

    var.m_varType = Tools::VT_LONG;
    var.m_val.lVal = SpatialIndex::RTree::RV_RSTAR;
    ps->setProperty("TreeVariant", var);

    // Index* idx = new Index(*ps);
    MyDataStream stream(argv[1]);

    string filename = "spatial_index";
    IStorageManager* diskfile = StorageManager::createNewDiskStorageManager(filename, 65536);
    StorageManager::IBuffer* file = StorageManager::createNewRandomEvictionsBuffer(*diskfile, 10, false);

    id_type indexIdentifier;

    ISpatialIndex* tree = RTree::createAndBulkLoadNewRTree(
        RTree::BLM_STR, stream, *file, 0.9, 1024, 1024, 3, SpatialIndex::RTree::RV_RSTAR, indexIdentifier
    );
    tree->flush();
    file->flush();
    diskfile->flush();

    delete tree;
    delete ps;
    delete file;
    delete diskfile;

    cerr << "Index identifier: " << indexIdentifier << endl;

}
