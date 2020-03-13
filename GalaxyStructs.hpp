#ifndef GALAXYSTRUCTS_HPP
#define GALAXYSTRUCTS_HPP

#include <vector>
#include <map>
#include <string>
#include <experimental/optional>

using namespace std;
using namespace std::experimental;

struct System {
    double x;
    double y;
    double z;
    unsigned long int id64;
    bool isNeutron;
    bool isScoopable;
};

struct Body {
    unsigned long int id64;
    bool isMainStar;
    unsigned long int distanceToArrival;
    string type;
    string subtype;
};

enum class ParseField {
    none,
    x,
    y,
    z,
    id64,
    type,
    subtype,
    main_star,
    distance_to_arrival,
    coords,
    bodies
};

enum class ParseSection {
    none,
    system,
    controlling_faction,
    coords,
    bodies,
    solid_compositions,
    atmosphere_compositions,
    materials,
    belts,
    rings,
    stations,
    discovery,
    parents,
    factions,
    faction_active_states,
    faction_pending_states,
    faction_recovering_states,
    import_commodities,
    export_commodities,
    prohibited_commodities,
    market,
    ships,
    modules,
    services,
	same
};

enum class ParseTypes {
    unknown, integer, real, scalar, boolean,
    optional_integer, optional_real, optional_scalar, optional_boolean,
    vector_scalar
};

enum class BodyTypes {
    star,
    planet
};

enum class BodySubtypes {
    unknown,
    neutron_star,
    a_star,
    b_star,
    f_star,
    g_star,
    k_star,
    m_star,
    o_star
};

struct KeyLookup {
    const char *name;
    ParseSection within_section;
    ParseSection current_section;
    ParseSection next_section;
    ParseField next_value;
    long int offset;
	ParseTypes next_type;
};

#endif
