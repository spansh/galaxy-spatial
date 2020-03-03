/* C++ code produced by gperf version 3.0.4 */
/* Command-line: gperf -t --output-file=BodySubtypesHash.hpp body_subtypes.gperf  */
/* Computed positions: -k'1,8' */

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

#line 1 "body_subtypes.gperf"


#include "GalaxyStructs.hpp"

#line 14 "body_subtypes.gperf"
struct BodySubtypeHash {
    const char* name;
    BodySubtypes subtype;
    bool isScoopable;
};
/* maximum key range = 27, duplicates = 0 */

class BodySubtypeKey
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static const struct BodySubtypeHash *Lookup (const char *str, unsigned int len);
};

inline unsigned int
BodySubtypeKey::hash (register const char *str, register unsigned int len)
{
  static const unsigned char asso_values[] =
    {
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39,  0, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39,  0, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39,  5,  0, 39, 39, 39,
       0,  0, 39, 39, 39,  0, 39,  5,  0, 15,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      15,  0, 39,  0, 39, 39, 39, 39, 39, 39,
      39,  0, 39, 39, 39,  0, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39, 39, 39, 39, 39,
      39, 39, 39, 39, 39, 39
    };
  return len + asso_values[(unsigned char)str[7]] + asso_values[(unsigned char)str[0]];
}

const struct BodySubtypeHash *
BodySubtypeKey::Lookup (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 15,
      MIN_WORD_LENGTH = 12,
      MAX_WORD_LENGTH = 33,
      MIN_HASH_VALUE = 12,
      MAX_HASH_VALUE = 38
    };

  static const struct BodySubtypeHash wordlist[] =
    {
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
#line 21 "body_subtypes.gperf"
      {"Neutron Star", BodySubtypes::neutron_star,false},
      {"",BodySubtypes::unknown,false},
#line 27 "body_subtypes.gperf"
      {"F (White) Star",BodySubtypes::f_star,true},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
      {"",BodySubtypes::unknown,false},
#line 25 "body_subtypes.gperf"
      {"B (Blue-White) Star",BodySubtypes::b_star,true},
      {"",BodySubtypes::unknown,false},
#line 29 "body_subtypes.gperf"
      {"G (White-Yellow) Star",BodySubtypes::g_star,true},
#line 31 "body_subtypes.gperf"
      {"K (Yellow-Orange) Star",BodySubtypes::k_star,true},
#line 33 "body_subtypes.gperf"
      {"M (Red giant) Star",BodySubtypes::m_star,true},
#line 23 "body_subtypes.gperf"
      {"A (Blue-White) Star", BodySubtypes::a_star,true},
      {"",BodySubtypes::unknown,false},
#line 26 "body_subtypes.gperf"
      {"F (White super giant) Star",BodySubtypes::f_star,true},
      {"",BodySubtypes::unknown,false},
#line 30 "body_subtypes.gperf"
      {"K (Yellow-Orange giant) Star",BodySubtypes::k_star,true},
#line 34 "body_subtypes.gperf"
      {"M (Red super giant) Star",BodySubtypes::m_star,true},
      {"",BodySubtypes::unknown,false},
#line 24 "body_subtypes.gperf"
      {"B (Blue-White super giant) Star",BodySubtypes::b_star,true},
      {"",BodySubtypes::unknown,false},
#line 28 "body_subtypes.gperf"
      {"G (White-Yellow super giant) Star",BodySubtypes::g_star,true},
#line 35 "body_subtypes.gperf"
      {"O (Blue-White) Star",BodySubtypes::o_star,true},
      {"",BodySubtypes::unknown,false},
#line 22 "body_subtypes.gperf"
      {"A (Blue-White super giant) Star", BodySubtypes::a_star,true},
      {"",BodySubtypes::unknown,false},
#line 32 "body_subtypes.gperf"
      {"M (Red dwarf) Star",BodySubtypes::m_star,true}
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
