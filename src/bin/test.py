import  hashlib

def generateLicense(email):
    array = []

    hashObject = hashlib.md5(email.encode('utf-8'))
    hexDigest = hashObject.hexdigest()

    for i in range(0, len(hexDigest),5):
        if i < 21:
            flag = hexDigest[i:i + 5]
            array.append(flag)
        else:
            pass
        licenseKey = '-'.join(array)

    return licenseKey

if __name__ == '__main__':
    emailInput = input('请输入Email:')

    licenseKey = generateLicense(emailInput)
    listen = '{\n   "email" : "' +str(emailInput) + '",\n    "license_key" : "' + format(licenseKey) + '"\n}'

    print(listen)
