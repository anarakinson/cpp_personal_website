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
2. Install all packages from `requirements.txt`

3. Run 'docker-compose up' and open port '3333'

### Notice:
If you are using `SSLServer` on localhost - don't forget replace `http://localhost` with `https://localhost`



### Web hosting

This site is working in docker container on https://anarakinson.onrender.com/

Notice, that web hosting is free and very slow because of it.
