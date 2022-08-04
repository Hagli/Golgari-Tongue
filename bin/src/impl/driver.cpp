#include "../header/driver.h"

static void HandleNumber() {
  if (ParseNumberExpr()) {
    fprintf(stderr, "Parsed a number definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

static void HandleTurn() {
  if (ParseTurnExpr()) {
    fprintf(stderr, "Parsed a turn definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

static void HandleIdentifier() {
  if (ParseIdentifierExpr()) {
    fprintf(stderr, "Parsed a identifier definition.\n");
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

#include <iostream>
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
        case tok_identifier:
          HandleIdentifier();
          break;
        case tok_eof:
          return 0;
      }
    }
}