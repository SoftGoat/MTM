import json, os

ENCRYPT=1
DECRYPT=-1

LOWER=('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
UPPER=('A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z')

def changeChar(char, num):  
    if char.isupper():
        charOrder=UPPER.index(char)
        return UPPER[(num+charOrder)%len(UPPER)]
    if char.islower():
        charOrder=LOWER.index(char)
        return LOWER[(num+charOrder)%len(LOWER)]
        

class CaesarCipher:
    def __init__(self, num):
        self.num=num
    
    def changeString(self, string ,mode):
        newString=""
        for char in string:
            if char.isalpha():
                newString+=changeChar(char,self.num*mode)
            else:
                newString+=char
        return newString   
        
    def encrypt(self,string):
        return self.changeString(string, ENCRYPT)
    
    def decrypt (self, string):
        return self.changeString(string, DECRYPT)

    def key_shift(self, delta):
        self.num+=delta


class VigenereCipher:
    def __init__(self, key):
        self.key=key

    def changeString (self, string, mode):
        newString=""
        keyIndex=0
        for char in string:
            if char.isalpha():
                newString+=changeChar(char,self.key[keyIndex]*mode)
                keyIndex=(keyIndex+1)%len(self.key)
            else:
                newString+=char
        return newString
    
    def encrypt(self,string):
        newString= self.changeString(string,ENCRYPT)
        return(newString)
    
    def decrypt(self,string):
        return self.changeString(string,DECRYPT)
    

def loadEncryptionSystem(dir_path, plaintext_suffix):
    jsonPath=os.path.join(dir_path,'config.json')
    with open(jsonPath, 'r') as f:
        dictionary = json.load(f)
        if dictionary["type"]=="Caesar":
            chiper=CaesarCipher(dictionary["key"])
        if dictionary["type"]=="Vigenere":       
            chiper=VigenereCipher(dictionary["key"]) 
          
        if dictionary["encrypt"]=="True":
            encrypt=True
        if dictionary["encrypt"]=="False":
            encrypt=False
    for file in os.listdir(dir_path):
        filePath = os.path.join(dir_path,file)
        fileName=os.path.splitext(file)[0]
        fileSuffix=os.path.splitext(file)[1]
        if encrypt:    
            if fileSuffix=="."+plaintext_suffix:
                with open(filePath ,'r') as readFile:
                    writeFilePath=os.path.join(dir_path,fileName+".enc")
                    with open(writeFilePath,'w') as writeFile:
                        encrypted=chiper.encrypt(readFile.read())
                        writeFile.write(encrypted)
        else:
            if fileSuffix==".enc":
                with open(filePath ,'r') as readFile:
                    writeFilePath=os.path.join(dir_path,fileName+"."+plaintext_suffix)
                    with open(writeFilePath,'w') as writeFile:
                        decrypted=chiper.decrypt(readFile.read())
                        writeFile.write(decrypted)


