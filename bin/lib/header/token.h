enum Token {
    tok_eof = -1,

    //control point or phase
    // turn, upkeep, main1, battle, main2, end
    tok_turn = -2, //turn has it's own token since it is a special type of phase
    tok_phase = -3,

    //action
    //play, attack, pass, end
    tok_action = -4,

    //primary
    tok_permanent = -5, //objects ("spells/lands")
    tok_number = -6,
};