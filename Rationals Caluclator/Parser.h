#ifndef PARSE_H
#define PARSE_H

#include "Rational.h"
#include "Scanner.h"

namespace rational374 {

class Parser {
 public:
  explicit Parser(Scanner* scanner);

  /**
   * Returns value of next expression on current input line.
   * If errors are detected, a bogus numerber like 0/0 is returned.
   * <expr> ::= <term> | <expr> + term | <expr> - <term>
   */
  Rational expr();

 private:
  /* <term> ::= <factor> | <term> * <factor> | <term> % <factor> */
  Rational term();

  /* <factor> ::= <int> | <int> / <int> | ( <expr> ) */
  Rational factor();

  Scanner* scanner_;
};

}  // namespace rational374

#endif
