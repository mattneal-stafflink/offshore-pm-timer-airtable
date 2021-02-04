/* 
*   {Presented To Owner Timer}
*
*   
*/

IF(
    WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {End Time Business Hours *} , 10, 'hour') ) > 1,
    IF(
        WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {End Time Business Hours *}, 10, 'hour' ) ) >= 1, 
        IF( 
            WORKDAY_DIFF( DATEADD({Start Time Business Hours *}, 10, 'hour'), DATEADD({End Time Business Hours *}, 10, 'hour') ) >= 3, 
            ( WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {End Time Business Hours *}, 10, 'hour' ) ) - 2) * 36000, 
            FALSE() 
        ) 
    ) + ( (64800 - (HOUR(DATEADD({Start Time Business Hours *}, 10, 'hours') ) * 3600)) - ((MINUTE({Start Time Business Hours *}) * 60)) + ((HOUR(DATEADD({Application Tagged As Handed Over}, 10, 'hours')) * 3600) - 28800) + (MINUTE({End Time Business Hours *}) * 60)),
    ((64800 - (HOUR(DATEADD({Start Time Business Hours *}, 10, 'hours') ) * 3600)) - ((MINUTE({Start Time Business Hours *}) * 60)) + ((HOUR(DATEADD({Application Tagged As Handed Over}, 10, 'hours')) * 3600) - 28800) + (MINUTE({End Time Business Hours *}) * 60) - 36000)
)