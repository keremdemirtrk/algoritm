#Dosya girintileme Writed by Kerem Demirturk
fileObjectRead = open('source.c', 'r+')
lines = fileObjectRead.readlines()
fileObjectRead.close()



tabCount = 0

fileObjectWrite = open('source2.c', 'w') # aynı dosyaya kaydedilsin istenirse source.c ile değiştirebilirsiniz.
for line in lines:
	if '}' in line:
		tabCount -= 1

	updatedLine = tabCount * '\t' + line;
	print(updatedLine, end='')
	fileObjectWrite.write(updatedLine)
	
	if '{' in line:
		tabCount += 1
	

fileObjectWrite.close()
