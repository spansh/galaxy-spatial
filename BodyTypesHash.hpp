/* C++ code produced by gperf version 3.0.4 */
/* Command-line: gperf -t --output-file=BodyTypesHash.hpp body_types.gperf  */
/* Computed positions: -k'' */

#line 1 "body_types.gperf"


#include "GalaxyStructs.hpp"

#line 14 "body_types.gperf"
struct BodyTypeHash {
    const char* name;
    BodyTypes type;
};
/* maximum key range = 3, duplicates = 0 */

class BodyTypeKey
{
private:
  static inline unsigned int hash (const char *str, unsigned int len);
public:
  static const struct BodyTypeHash *Lookup (const char *str, unsigned int len);
};

inline /*ARGSUSED*/
unsigned int
BodyTypeKey::hash (register const char *str, register unsigned int len)
{
  return len;
}

const struct BodyTypeHash *
BodyTypeKey::Lookup (register const char *str, register unsigned int len)
{
  enum
    {
      TOTAL_KEYWORDS = 2,
      MIN_WORD_LENGTH = 4,
      MAX_WORD_LENGTH = 6,
      MIN_HASH_VALUE = 4,
      MAX_HASH_VALUE = 6
    };

  static const struct BodyTypeHash wordlist[] =
    {
      {"",BodyTypes::star}, {"",BodyTypes::star},
      {"",BodyTypes::star}, {"",BodyTypes::star},
#line 20 "body_types.gperf"
      {"Star", BodyTypes::star},
      {"",BodyTypes::star},
#line 21 "body_types.gperf"
      {"Planet", BodyTypes::planet}
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
