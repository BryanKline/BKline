# Bryan Kline 
# bkline@unr.edu
# July 19th, 2016
#
# Python 2 script to isolate new data in barcode scanner text file, BARCODES.txt, 
# and write it to a new file, buffer.txt, while maintaining a growing list of 
# previously scanned data, masterList.txt, which is updated when the program is 
# executed.  The file buffer.txt can then be exported to a spreadsheet.
#

# Creates relative paths (might need to be changed to absolute paths for Windows
# depending on system in use at ASUN)
path1 = "masterList.txt"
path2 = "BARCODES.txt"
path3 = "buffer.txt"

# Opens files to be read, the inFiles, and one to be written to, the outFile, using 
# the paths to the files
inFile1 = open(path1, 'r')
inFile2 = open(path2, 'r')
outFile = open(path3, 'w')

# Iterates through the contents of the opened inFiles, which correspond to the 
# masterList.txt and BARCODES.txt files, line by line and if a line is different
# then it's written to the outFile, buffer.txt

for x, line2 in enumerate(inFile2):
	line1 = inFile1.readline()	
	if (line1 != line2):
		outFile.write(line2)

# The new entry total is written to the console, only for diagnostic purposes 
print("Total entries:")
print(x + 1)

# The files are closed
inFile1.close()
inFile2.close()
outFile.close()

# The buffer.txt file is opened for reading and masterList.txt is opened for 
# appending
inFile3 = open(path3, 'r')
outFile2 = open(path1, 'a')

# The data from buffer.txt is appended to masterList.txt so that it is now
# updated for the next time data is added
for y, line3 in enumerate(inFile3):
	outFile2.write(line3)

# The files are closed
inFile3.close()
outFile2.close()

