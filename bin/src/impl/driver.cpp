#include "../header/driver.h"

int globalNum = 0;
static void HandleNumber() {
  if (auto dum = ParseNumberExpr()) {
    fprintf(stdout, "Parsed a number definition.\n");
    fprintf(stdout, "The number is %d.\n", dum->getNum());
  } else {
    // Skip token for error recovery.
  }
}

static void HandleTurn() {
  if (auto dum = ParseTurnExpr()) {
    fprintf(stdout, "Parsed a turn definition.\n");
    globalNum = 0;
    fprintf(stdout, "It is turn %d.\n", dum->getTurn());
  } else {
    // Skip token for error recovery.
  }
}

static void HandlePermanent() {
  if (ParsePermanentExpr()) {
    fprintf(stdout, "Parsed a permanent definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

static void HandleAction() {
  if (ParseActionExpr()) {
    fprintf(stdout, "Parsed a action definition.\n");

  } else {
    // Skip token for error recovery.
  }
}

static void HandlePhase() {
  if (ParsePhaseExpr()) {
    fprintf(stdout, "Parsed a phase definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

int main() {
  fprintf(stdout, "ready> ");
    while(1){
      getNextToken(); //<- remember this is here fella ;)
      switch (getCurTok()) {
        case tok_turn:
          HandleTurn();
          fprintf(stdout, "ready> ");
          break;
        case tok_phase:
          HandlePhase();
          fprintf(stdout, "ready> ");
          break;
        case tok_action:
          HandleAction();
          fprintf(stdout, "ready> ");
          break;
        case tok_number:
          HandleNumber();
          fprintf(stdout, "ready> ");
          break;
        case tok_permanent:
          HandlePermanent();
          fprintf(stdout, "ready> ");
          break;
        case tok_eof:
          return 0;
        case 59:
          break;
      }
    }
}