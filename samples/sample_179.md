[<img src="../images/home.png"> Home ](https://github.com/VFPX/Win32API)  

# Creating hash values for the list of names

## Before you begin:

Hashing is also a common method of accessing data records. Considering a list of names, you can create an index, called a *hash table*, for all these names, when you would apply a formula to each name to produce a ***unique*** numeric value.  

See also:

[How to create an MD-5 Hash from a string](sample_483.md)  
  
***  


## Code:
```foxpro  
DECLARE INTEGER HashData IN shlwapi;
	STRING @pbData, LONG cbData,;
	STRING @pbHash, LONG cbHash

CREATE CURSOR csResult (hash C(20), name C(50))

* specifying the length of the hash
* cannot be larger than 256
PRIVATE nHashSize
nHashSize=8

* the following code creates a hash value
* for each name on the list

= CreateHashFromName("George Washington")
= CreateHashFromName("John Adams")
= CreateHashFromName("Thomas Jefferson")
= CreateHashFromName("James Madison")
= CreateHashFromName("James Monroe")
= CreateHashFromName("John Quincy Adams")
= CreateHashFromName("Andrew Jackson")
= CreateHashFromName("Martin van Buren")
= CreateHashFromName("William Henry Harrison")
= CreateHashFromName("John Tyler")
= CreateHashFromName("James K. Polk")
= CreateHashFromName("Zachary Taylor")
= CreateHashFromName("Millard Fillmore")
= CreateHashFromName("Franklin Pierce")
= CreateHashFromName("James Buchanan")
= CreateHashFromName("Abraham Lincoln")
= CreateHashFromName("Andrew Johnson")
= CreateHashFromName("Ulysses S. Grant")
= CreateHashFromName("Rutherford B. Hayes")
= CreateHashFromName("James A. Garfield")
= CreateHashFromName("Chester A. Arthur")
= CreateHashFromName("Grover Cleveland")
= CreateHashFromName("Benjamin Harrison")
= CreateHashFromName("Grover Cleveland")
= CreateHashFromName("William McKinley")
= CreateHashFromName("Theodore Roosevelt")
= CreateHashFromName("William H. Taft")
= CreateHashFromName("Woodrow Wilson")
= CreateHashFromName("Warren G. Harding")
= CreateHashFromName("Calvin Coolidge")
= CreateHashFromName("Herbert C. Hoover")
= CreateHashFromName("Franklin D. Roosevelt")
= CreateHashFromName("Harry S. Truman")
= CreateHashFromName("Dwight D. Eisenhower")
= CreateHashFromName("John F. Kennedy")
= CreateHashFromName("Lyndon B. Johnson")
= CreateHashFromName("Richard M. Nixon")
= CreateHashFromName("Gerald Ford")
= CreateHashFromName("Jimmy Carter")
= CreateHashFromName("Ronald Reagan")
= CreateHashFromName("George Bush")
= CreateHashFromName("Bill Clinton")
= CreateHashFromName("George W. Bush")

* the name is searched by the specified hash value
INDEX ON hash TAG hash
= SEEK(CreateHash("Herbert C. Hoover", m.nHashSize))

BROWSE NORMAL NOWAIT
* end of main

PROCEDURE CreateHashFromName(cName)
	LOCAL cHash
	cHash = CreateHash(m.cName, nHashSize)  && 16 bytes
	INSERT INTO csResult VALUES (m.cHash, m.cName)

FUNCTION CreateHash(cName, nHashSize)
	LOCAL cHash
	cHash = REPLICATE(CHR(0), nHashSize)

	IF HashData(@cName, LEN(m.cName), @cHash, nHashSize) = 0
		RETURN cHash
	ELSE
		RETURN 0
	ENDIF  
```  
***  


## Listed functions:
[HashData](../libraries/shlwapi/HashData.md)  

## Comment:
VFP actively uses hashing techniques. Here is one of its error messages related to hashing:  
  
**Error code: 4131***  
Hash conflict between #contextname1# and #contextname2#.  
The hash algorithm has generated the same hash value for both of the listed context strings.*  
  
***  

