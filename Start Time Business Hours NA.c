/*
*   Forumla for the {Start Time Business Hours *}.
*   To use, copy the formula ONLY. do not copy this note.
*   THIS FIELD DOES NOT EXIST IN PRODUCTION: It is the inner workings of a larger formula.
*
*   This formula does 2 things:
*   - If {Application Started Processing} + 10 hours (+10GMT) is greater than 0... 
*   - Add 8 hours, minus the hours from the {application started processing} field.
*   ELSE:
*   - If {Application Started Processing} is before 8am, change time to 8am.
*   - IF {Application Started Processing} is AFTER 6pm, change time to 6pm.
*
*/

// Functioning example:

IF( 
   HOUR(DATEADD({Application Started Processing}, 10, 'hours')) < 0,  
    DATEADD({Application Started Processing}, (8 - HOUR({Application Started Processing})), 'hour'),
    IF( 
        HOUR(DATEADD({Application Started Processing}, 10, 'hours')) < 8, 
        DATEADD({Application Started Processing}, (36480 - ((HOUR(DATEADD({Application Started Processing}, 10, 'hours')) * 60)) - MINUTE({Application Started Processing})), 'minute'),
        IF( 
            HOUR(DATEADD({Application Started Processing}, 10, 'hours')) > 18, 
            DATEADD({Application Started Processing}, -((HOUR({Application Started Processing}) * 60) + MINUTE({Application Started Processing}) - 1080), 'minute'),
            {Application Started Processing}
        )
    )
)

//  reusable version:
// Set {asp} to your start time.
/*
*   This example has a field with a start time called 'asp', and the business hours are set by another field called {Open Time} and {close Time}
*   {Timezone} is a number, which is +/- 0GMT. For example, set this field to '0' for GMT. Brisbane is '10'. etc.
*/
IF( 
   HOUR(DATEADD({asp}, {Timezone}, 'hours')) < 0,  
    DATEADD({asp}, ({Open Time} - HOUR({asp})), 'hour'),
    IF( 
        HOUR(DATEADD({asp}, {Timezone}, 'hours')) < {Open Time}, 
        DATEADD({asp}, (36480 - ((HOUR(DATEADD({asp}, {Timezone}, 'hours')) * 60)) - MINUTE({asp})), 'minute'),
        IF( 
            HOUR(DATEADD(asp, {Timezone}, 'hours')) > {close Time}, 
            DATEADD({asp}, -((HOUR({asp}) * 60) + MINUTE({asp}) - 1080), 'minute'),
            {asp}
        )
    )
)