/*
*   Forumla for the {Application Tagged As Handed Over}.
*   To use, copy the formula ONLY. do not copy this note.
*   THIS FIELD DOES NOT EXIST IN PRODUCTION: It is the inner workings of a larger formula. {Handover Timer}
*
*/

IF( 
   HOUR(DATEADD({Application Tagged As Handed Over}, 10, 'hours')) < 0,  
    DATEADD({Application Tagged As Handed Over}, (8 - HOUR({Application Tagged As Handed Over})), 'hour'),
    IF( 
        HOUR(DATEADD({Application Tagged As Handed Over}, 10, 'hours')) < 8, 
        DATEADD({Application Tagged As Handed Over}, (36480 - ((HOUR(DATEADD({Application Tagged As Handed Over}, 10, 'hours')) * 60)) - MINUTE({Application Tagged As Handed Over})), 'minute'),
        IF( 
            HOUR(DATEADD({Application Started Processing}, 10, 'hours')) > 18, 
            DATEADD({Application Tagged As Handed Over}, -((HOUR({Application Tagged As Handed Over}) * 60) + MINUTE({Application Tagged As Handed Over}) - 1080), 'minute'),
            {Application Tagged As Handed Over}
        )
    )
)