import os

def encrypt(file,key):
    with open (file,'rb') as fle:
        binary_data=fle.read()


        key_byte=key.encode()
        key_len=len(key_byte)

        outputdata=bytearray()

        for i in range(len(binary_data)):
            encrypted_byte=binary_data[i] ^ key_byte[i%key_len]
            outputdata.append(encrypted_byte)

        print("encryption ended")
    

    with open(file,'wb') as outputfile:
        outputfile.write(outputdata)


def encryptfolder(folderpath,key):
    for dirpath,dirnames,filenames in os.walk(folderpath):
        for filename in filenames:
            file=os.path.join(dirpath,filename)
            encrypt(file,key)

folderpath=input("enter the folder path:")
key=input("enter the password")
encryptfolder(folderpath,key)
