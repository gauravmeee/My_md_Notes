
Create file
```sh
# create an empty file and empty if already exist
nul > index.html
```


Problem : Running scripts is disabled on this system (PowerShell error)
Solution : Use `Command Prompt`  or Change the `execution policy` of Powershell


```sh
# Power Shell

# Check Execution Policy
Get-ExecutionPolicy

# Set Execution policy to RemoteSigned
Set-ExecutionPolicy RemoteSigned

# Set Execution policy to Unrestricted
Set-ExecutionPolicy Unrestricted

# Revert the Execution policy if it was originally remoteSigned
Set-ExecutionPolicy RemoteSigned

# Revert the execution policy to unrestricted
Set-ExecutionPolicy Restricted
```

### Documentations
[Mongodb Documentation](https://www.mongodb.com/docs/manual/)
[Postman Documentation](https://learning.postman.com/docs/getting-started/overview/)
[npm packages Documentation](https://www.npmjs.com/package)
[Mongoose Documentation](https://mongoosejs.com/docs/)
[Validator Documentation](https://www.npmjs.com/package/validator) 
[HTTP Status Codes](https://developer.mozilla.org/en-US/docs/Web/HTTP/Status)
## Compare Nodejs vs Python
npm - pip
express - flask, django
package.json - requirements.txt


### Package Installers
chocolatey - npm installer
brew - mongodb installer