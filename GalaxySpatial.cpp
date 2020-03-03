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

#define REPORT_SIZE 50000
#define CLOSE_STAR 100

using namespace std;
using namespace std::experimental;
using namespace std::chrono;
using namespace rapidjson;

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
            return true;
        }
        bool String(const char* str, SizeType length, bool copy) {
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
                                    this->system.hasScoopable = true;
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

int main() {
    string filename = "galaxy.json.bz2";

    boost::iostreams::filtering_istream inputStream;
    inputStream.push(boost::iostreams::bzip2_decompressor());
    inputStream.push(boost::iostreams::file_source(filename));

    IStreamWrapper stream(inputStream);

    Handler handler;
    Reader reader;
    
    reader.IterativeParseInit();
    unsigned long int count = 0;
    high_resolution_clock::time_point t1,t2,t3;

    t1 = high_resolution_clock::now();
    t3 = t1;

    while (!reader.IterativeParseComplete() && !reader.HasParseError()) {
        reader.template IterativeParseNext<kParseDefaultFlags>(stream, handler);
        if (handler.isFinishedSystem) {
            count++;
            if (count % REPORT_SIZE == 0) {
                t2 = high_resolution_clock::now();
                duration<double> total_time_span = duration_cast<duration<double>>(t2 - t1);
                duration<double> last_time_span = duration_cast<duration<double>>(t2 - t3);
                cerr << "Finished system " << count << ": " << handler.system.id64 << "(" << handler.system.x << "," << handler.system.y << "," << handler.system.z << ") (";
                if (handler.system.isNeutron) {
                    cerr << "neutron/";
                } else {
                    cerr << "no neutron/";
                }
                if (handler.system.isScoopable) {
                    cerr << "is scoopable/";
                } else {
                    cerr << "not scoopable/";
                }
                if (handler.system.hasScoopable) {
                    cerr << "has nearby scoopable";
                } else {
                    cerr << "no nearby scoopable";
                }
                cerr << ") in " << last_time_span.count() << " seconds at " << (REPORT_SIZE / last_time_span.count()) << "/sec, total " << total_time_span.count() << " seconds at " << (count / total_time_span.count()) << "/sec" << endl;

                t3 = t2;
            }

            cout << 
                "INSERT INTO solar_system (id64,coords,is_neutron,is_scoopable,has_scoopable) VALUES (" <<
                handler.system.id64 <<
                ",ST_MakePoint(" <<
                handler.system.x << 
                "," <<
                handler.system.y <<
                "," <<
                handler.system.z <<
                ")," <<
                handler.system.isNeutron <<
                "," <<
                handler.system.isScoopable <<
                "," <<
                handler.system.hasScoopable <<
                ") ON CONFLICT DO NOTHING" << 
                endl;
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
