def encrypt(file,key):
    with open (file,'rb') as fle:
        binary_data=fle.read()


        key_byte=key.encode()
        key_len=len(key_byte)

        outputdata=bytearray()

        for i in range(len(binary_data)):
            encrypted_byte=binary_data[i] ^ key_byte[i%key_len]
            outputdata.append(encrypted_byte)
            if i%100==0:
                print(".",end="")

        print("encryption ended")
    

    with open(file,'wb') as outputfile:
        outputfile.write(outputdata)




file = input("enter file along with path")
key=input("enter password")
encrypt(file,key)
