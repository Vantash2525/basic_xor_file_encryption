this encrypt function encrypts a file also decrypts the file using the same password using during encryption , this is done using xor operation where the bytes of the data are xor with the mod value of the password
this is very basic , this method of encrytion is used during earlier days
this encrption method can be safely used by following 1) unpredictable random password 2) passoword should be as long as the data size 3) password used only once 

I also made a very few changes and created a python file what would encrypt all the file in a folder 

04/05/2025 today i created the same xor encryption using c , then also tried to alter the program by without using buffer by just directly changing the bytes through a loop by that takes lot of time to encrypt a small file which the other program just did within fraction of second but when i use the non buffer one it saves me a 90% of the memory
