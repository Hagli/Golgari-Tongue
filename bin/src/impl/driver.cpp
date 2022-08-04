#include "../header/driver.h"

int globalNum = 0;
static void HandleNumber() {
  if (ParseNumberExpr()) {
    fprintf(stderr, "Parsed a number definition.\n");
    std::unique_ptr<NumberExprAST> dum = ParseNumberExpr();
    fprintf(stderr, "%d\n", dum->getNum());
  } else {
    // Skip token for error recovery.
  }
}

static void HandleTurn() {
  if (ParseTurnExpr()) {
    fprintf(stderr, "Parsed a turn definition.\n");
    globalNum = 0;
  } else {
    // Skip token for error recovery.
  }
}

static void HandlePermanent() {
  if (ParsePermanentExpr()) {
    fprintf(stderr, "Parsed a permanent definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

static void HandleAction() {
  if (ParseActionExpr()) {
    fprintf(stderr, "Parsed a action definition.\n");

  } else {
    // Skip token for error recovery.
  }
}

static void HandlePhase() {
  if (ParsePhaseExpr()) {
    fprintf(stderr, "Parsed a phase definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

int main() {
    while(1){
      fprintf(stderr, "ready> ");
      getNextToken();
      switch (getCurTok()) {
        case tok_turn:
          HandleTurn();
          break;
        case tok_phase:
          HandlePhase();
          break;
        case tok_action:
          HandleAction();
          break;
        case tok_number:
          HandleNumber();
          break;
        case tok_permanent:
          HandlePermanent();
          break;
        case tok_eof:
          return 0;
      }
    }
}