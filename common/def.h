#ifndef MUST_DEF_H
#define MUST_DEF_H

#define MUST__DEF2(A, B)      MUST__DEF2__(A, B)
#define MUST__DEF3(A, B, C)   MUST__DEF3__(A, B, C)
#define MUST__DEF2__(A, B)    must_##A##_##B
#define MUST__DEF3__(A, B, C) must_##A##_##B##_##C

#endif
