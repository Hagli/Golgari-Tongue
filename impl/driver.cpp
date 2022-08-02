#include <stdio.h>
#include "../header/token.h"
#include "../header/driver.h"

static void HandleTurn() {
  if (ParseTurnExpr()) {
    fprintf(stderr, "Parsed a turn definition.\n");
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

static void HandleAction() {
  if (ParseActionExpr()) {
    fprintf(stderr, "Parsed a action definition.\n");
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

static void HandleNumber() {
  if (ParseNumberExpr()) {
    fprintf(stderr, "Parsed a number definition.\n");
  } else {
    // Skip token for error recovery.
  }
}

extern std::string IdentifierStr;
#include <iostream>
int main() {
    while(1){
      fprintf(stderr, "ready> ");
      getNextToken();
      switch (CurTok) {
        case tok_turn:
          HandleTurn();
          break;
        case tok_phase:
          std::cout<<IdentifierStr<<'\n';
          HandlePhase();
        case tok_action:
          HandleAction();
        case tok_number:
          HandleNumber();
        case tok_identifier:
          HandleIdentifier();
          break;
        case tok_eof:
          return 0;
      }
    }
}