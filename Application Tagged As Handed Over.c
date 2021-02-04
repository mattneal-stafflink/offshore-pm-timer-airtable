/*
*   Forumla for the Application Tagged As Handed Over field.
*   To use, copy the formula ONLY. do not copy this note.
*
*   Checks if {Application Handover Status} field has a value, then grabs time it was last modified,
*   formats it, then parses it back as a date item. If the statement is false, return the current time.
*
*/



IF(
    {Application Handover Status},
    DATETIME_PARSE(DATETIME_FORMAT(LAST_MODIFIED_TIME({Application Handover Status}), 'D/M/Y h:mm A' ), 'D/M/YYYY h:mm A'),
    NOW()
)