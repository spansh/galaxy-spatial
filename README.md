# galaxy-spatial
Generate spatial database insert statements from https://downloads.spansh.co.uk/galaxy.json.bz2

* Requires a checkout of rapidjson in the same directory from https://github.com/Tencent/rapidjson.git
* Requires libspatialindex compiled and installed from https://libspatialindex.org/
* Requires the Boost libraries installed from https://www.boost.org/
* In order to create the various Hash.hpp files it requres gnu gperf from https://www.gnu.org/software/gperf/ then ```make gperf```

