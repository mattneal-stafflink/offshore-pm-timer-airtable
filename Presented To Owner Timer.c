/* 
*   {Presented To Owner Timer}

If {Presented Completed Application to Owner}, Display time difference between {Presented Completed Application to Owner} and {Start Time Business Hours *}.
*
*   
*/

IF(
    {Presented Completed Application to Owner},
    IF(
        WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {Presented Completed Application to Owner}, 10, 'hour' ) ) > 1,
        IF( 
            WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {Presented Completed Application to Owner}, 10, 'hour' ) ) >= 1,
            IF(
                WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {Presented Completed Application to Owner}, 10, 'hour' ) ) >= 3,
                ( WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( {Presented Completed Application to Owner}, 10, 'hour' ) ) - 2 ) * 36000,
                FALSE()
            )
        ) + ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( {Presented Completed Application to Owner} ) * 60 ) ),
        ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( {Presented Completed Application to Owner} ) * 60 ) - 36000 )
    ),
    IF(
        WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) > 1,
        IF( 
            WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) >= 1,
            IF(
                WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) >= 3,
                ( WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) - 2 ) * 36000,
                FALSE()
            )
        ) + ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( NOW() ) * 60 ) ),
        ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( NOW() ) * 60 ) - 36000 )
    )

)



// Make this the business hoursdifferencebetweenn now and Start Time Business Hours.

    IF(
        WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) > 1,
        IF( 
            WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) >= 1,
            IF(
                WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) >= 3,
                ( WORKDAY_DIFF( DATEADD( {Start Time Business Hours *}, 10, 'hour' ), DATEADD( NOW(), 10, 'hour' ) ) - 2 ) * 36000,
                FALSE()
            )
        ) + ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( NOW() ) * 60 ) ),
        ( ( 64800 - ( HOUR( DATEADD( {Start Time Business Hours *}, 10, 'hour' ) ) * 3600 ) ) - ( ( MINUTE( {Start Time Business Hours *} ) * 60 ) ) + ( ( HOUR( DATEADD( {Application Tagged As Handed Over}, 10, 'hours' ) ) * 3600 ) - 28800 ) + ( MINUTE( NOW() ) * 60 ) - 36000 )
    )