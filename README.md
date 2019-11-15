# BPlusTree-BD

1. sudo docker login (poes suas credenciais)
2. sudo docker pull loreanunciacao/bplusstree-template
3. sudo docker run --name tp2 -it -d loreanunciacao/bplusstree-template
4. sudo docker exec -ti tp2 bash (aqui vc entra no docker)
5. cd bplusstree/BPlussTree-BD/scr
6. g++ upload.cpp support/hashFile.cpp support/parser.cpp -o upload
7. ./upload ../arquivo.csv
