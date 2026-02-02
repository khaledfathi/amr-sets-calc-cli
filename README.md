# Amr Sets Calculator CLI 


> CLI application to Read CSV file with 2 column , check repeated Values from Col A with Col B  and vice versa , and get complement of A in B and vice versa . 

---
```
amrsets -h 
```
```bash
Calculats Sets from CSV file 

Amr sets calculator [OPTION...] <FILE>


POSITIONALS:
  FILE TEXT:FILE REQUIRED     CSV file to process 

OPTIONS:
  -h,     --help              Print this help message and exit 
  -a,     --repeated-a-b      get repeated from column A in column B 
  -b,     --repeated-b-a      get repeated from column B in column A 
  -A,     --complement-a-b    get complement from column A in column B 
  -B,     --complement-b-a    get complement from column B in column A 
  -t,     --show-table        show the csv table 
          --all               same as -a -b -A -B -t 
  -v,     --version           Display program version information and exit 
```

### Examples : 

##### show table 
```bash
amrsets  -t file.csv 
```
```
+----------+----------+
|  Col A   |  Col B   |
+----------+----------+
|    32    |    3     |
|    33    |    33    |
|    34    |    5     |
|    35    |    6     |
|    36    |    33    |
|    37    |    8     |
|    38    |    9     |
|    39    |    10    |
|    40    |    33    |
|    41    |    12    |
|    42    |    13    |
|          |    14    |
|          |    33    |
|          |    16    |
+----------+----------+
```

##### repeated values from Col A in Col B , with how many time repeated  
```bash
amrsets  -a file.csv 
```
```bash
Repated A -> B : 
[ 33 -> 4 ]
```
##### complement values Col A for Col B  
``` bash
amrsets  -A file.csv 
```
```bash
Complement A -> B : 
[ 32 , 34 , 35 , 36 , 37 , 38 , 39 , 40 , 41 , 42 ]
```