# offshore-pm-timer-airtable
A series of Airtable formulas to calculate the time it takes for the offshore team to do a task, as well as on shore PM team members.

Setting Up Airtable Rental Applications Base To Track Offshore Processing, And time to Presented to Owner by PM

* Track Offshore processing time
* Track the time it takes a PM to present a completed application to property owner
* Exclude weekends and out of business hours time

A point of contention is time taken by offshore staff and PM’s to process rental property applications. In order to gauge this accurately, we’ve created a process of tracking application processing start times, handover time, and presented to owner time. Normally, this would be easy; simply subtract the two date times from each other. The problem is, this doesn’t take into account weekend hours or out of business hours. Our formula DOES NOT count hours outside of business hours. For example, if the offshore team start processing at 4pm on a Friday and finish at 10am Monday, the time recorded for this task is only 4 hours, not 60+.

Requirements:

* Status Field (single select)
    * Processing
    * Complete
    * Etc
* Application Started Processing (Formula)
    * Local date format
    * Include a time field
    * Disable “Use the same time zone (GMT) for all collaborators
* Handover Timer (Formula)
    * Duration Format
* Application Handover Status (Single Select)
    * Complete
    * Incomplete
    * N/A
* Application Tagged As Handed Over (formula)
    * Local date format
    * Include a time field
    * Disable “Use the same time zone (GMT) for all collaborators
* Presented to Owner Timer (Formula)
    * Duration Format
* Presented Completed Application to Owner (Date Field; manual entry)
    * Include a time field
    * Disable “Use the same time zone (GMT) for all collaborators


Caveats

* You MUST exclude any entries without a value for {Presented Completed Application to Owner}. Without doing so will massively skew the results in favour of the PM’s. 
