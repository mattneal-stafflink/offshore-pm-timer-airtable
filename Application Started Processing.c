/*
*   Forumla for the {Application Started Processing} field.
*   To use, copy the formula ONLY. do not copy this note.
*
*   This field Checks if the {Status} field has a value, then grabs the last modified time, 
*   formats it, then parses it back as a date item.
*
*/



IF(
    {Status},
    DATETIME_PARSE(DATETIME_FORMAT(LAST_MODIFIED_TIME(Status), 'D/M/Y h:mm A' ), 'D/M/YYYY h:mm A'),
    NOW()
)