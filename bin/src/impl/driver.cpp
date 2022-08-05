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
  if (auto dum = ParsePermanentExpr()) {
    fprintf(stdout, "Parsed a permanent definition.\n");
    fprintf(stdout, "It's %s.\n", dum->getIdent().c_str());
  } else {
    // Skip token for error recovery.
  }
}

static void HandleAction() {
  if (auto dum = ParseActionExpr()) {
    fprintf(stdout, "Parsed a action definition.\n");
    fprintf(stdout, "Action is %s.\n", dum->getActName().c_str());
    fprintf(stdout, "With %d %s(s).\n", dum->getNum()->getNum(), dum->getIdent()->getIdent().c_str());
  } else {
    // Skip token for error recovery.
  }
}

static void HandlePhase() {
  if (auto dum = ParsePhaseExpr()) {
    fprintf(stdout, "Parsed a phase definition.\n");
    fprintf(stdout, "Phase is %s.\n", dum->getPhaseName().c_str());
    auto dam = dum->getAction();
    fprintf(stdout, "With %d %s(s).\n", dam->getNum()->getNum(), dam->getIdent()->getIdent().c_str());
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