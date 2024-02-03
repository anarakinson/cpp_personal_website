# Website project

1. Install vcpkg:
```cmd
git clone https://github.com/Microsoft/vcpkg.git
```
if WINDOWS:
```cmd
.\vcpkg\bootstrap-vcpkg.bat
```
else:
```shell
./vcpkg/bootstrap-vcpkg.sh
```

```cmd
./vcpkg/vcpkg integrate install

./vcpkg/vcpkg list

```

### Notice:
If you using `SSLServer` on localhost - don't forget replace `http://localhost` with `https://localhost`

