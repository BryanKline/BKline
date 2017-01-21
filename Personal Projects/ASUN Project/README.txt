
NewScanData

Brief:

Small script produced for a university organization to manage bar code scanner
data.

Detailed:

This is a small script that I wrote for the program officer in charge of program
data at a previous place of employment, ASUN (Association of Students at the 
University of Nevada).  ASUN provides a free service to the entire student body 
which offers transportation within and up to three away from the UNR campus and
they maintain information on the students that use their service.

While a computer science and engineering student at UNR, and while myself employed at 
ASUN as a bus driver, I was contacted about writing a small script to manage the
information collected from the users of the transport service.  The user data was collected
via bar code scanners which read student IDs and was then dumped into a spreadsheet.  
This data dump caused the problem of duplicated data as the bar code scanners retained 
old scan data so that each dump into the spreadsheet would always dump new data as well
as data that had already been dumped.

I was asked to write something that would allow only the new data data to be dumped 
to the spreadsheet, and to do it in Python.  I produced for ASUN a small script that
will maintain a text file of all previously read in data and then compare that with
the data currently on the scanner, find only the new data, write that to a new
file which can be dumped into the spreadsheet, and then update the file containing
previously read data.
