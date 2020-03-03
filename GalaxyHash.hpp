/* C++ code produced by gperf version 3.0.4 */
/* Command-line: gperf -t --output-file=GalaxyHash.hpp galaxy.gperf  */
/* Computed positions: -k'1' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
#error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 1 "galaxy.gperf"


#include "GalaxyStructs.hpp"
#include <cstddef>

#line 15 "galaxy.gperf"
struct KeyLookup;
/* maximum key range = 21, duplicates = 0 */

class GalaxyKey
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static const struct KeyLookup *Lookup (const char *str, unsigned int len);
};

inline unsigned int
GalaxyKey::hash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 15, 10,
       0, 22, 22, 22, 22,  5, 22, 22, 22,  0,
      22, 22, 22, 22, 22,  0,  0, 22, 22, 22,
      10,  5,  0, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22, 22, 22, 22, 22,
      22, 22, 22, 22, 22, 22
    };
  return len + asso_values[(unsigned char)str[0]];
}

const struct KeyLookup *
GalaxyKey::Lookup (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 10,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 17,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 21
    };

  static const struct KeyLookup wordlist[] =
    {
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 22 "galaxy.gperf"
      {"z", ParseSection::coords,ParseSection::same,ParseSection::same,ParseField::z,offsetof(System,z),ParseTypes::real},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 25 "galaxy.gperf"
      {"type", ParseSection::bodies,ParseSection::same,ParseSection::same,ParseField::type,offsetof(Body,type),ParseTypes::scalar},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 21 "galaxy.gperf"
      {"y", ParseSection::coords,ParseSection::same,ParseSection::same,ParseField::y,offsetof(System,y),ParseTypes::real},
#line 26 "galaxy.gperf"
      {"subType", ParseSection::bodies,ParseSection::same,ParseSection::same,ParseField::subtype,offsetof(Body,subtype),ParseTypes::scalar},
#line 24 "galaxy.gperf"
      {"mainStar", ParseSection::bodies,ParseSection::same,ParseSection::same,ParseField::main_star,offsetof(Body,isMainStar),ParseTypes::boolean},
#line 18 "galaxy.gperf"
      {"id64", ParseSection::system,ParseSection::same,ParseSection::same,ParseField::id64,offsetof(System,id64),ParseTypes::integer},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 20 "galaxy.gperf"
      {"x", ParseSection::coords,ParseSection::same,ParseSection::same,ParseField::x,offsetof(System,x),ParseTypes::real},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 19 "galaxy.gperf"
      {"coords", ParseSection::system,ParseSection::coords,ParseSection::system,ParseField::none,-1,ParseTypes::unknown},
#line 27 "galaxy.gperf"
      {"distanceToArrival", ParseSection::bodies,ParseSection::same,ParseSection::same,ParseField::distance_to_arrival,offsetof(Body,distanceToArrival),ParseTypes::integer},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
      {"",ParseSection::same,ParseSection::same,ParseSection::same,ParseField::none,-1,ParseTypes::unknown},
#line 23 "galaxy.gperf"
      {"bodies", ParseSection::system,ParseSection::bodies,ParseSection::system,ParseField::none,-1,ParseTypes::unknown}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register int key = hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= 0)
        {
          register const char *s = wordlist[key].name;

          if (*str == *s && !strcmp (str + 1, s + 1))
            return &wordlist[key];
        }
    }
  return 0;
}
