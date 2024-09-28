# README

Google Test 環境をDockerで構築する手順を説明する。

## Dockerの実行手順

1. **Dockerイメージをビルドする**

   はじめに使用する前にDocker Image をBuildします。   
   一度Buildしたらそれ以降はBuildしなくて問題ないです。  
   
   Dockerfileがあるディレクトリに移動します。

   次に、以下のコマンドを実行してDockerイメージをビルドします。

   ```shell
   docker build -t test-env .
   ```

   ここで、`test-env`はビルドするイメージの名前です。  
   好きにつけてもらって構いませんが忘れないようにしてください。

2. **Dockerコンテナを実行する**

   **初回のみ**以下のコマンドでコンテナを実行します。カレントディレクトリをコンテナ内の`/app`にマウントします。

   ```shell
    docker run -it --name test-env -v %cd%:/app test-env
   ```

   これにより、コンテナ内の`/app`ディレクトリにホストのカレントディレクトリがマウントされます。
   
   また、--name test-envとすることで、作成したコンテナに名前が付きます。

   **初回以降**は以下の手順でコンテナを起動してください。

    - **コンテナの停止：**
  
    ```bash
    docker stop test-env
    ```

    - **コンテナの再起動：**

    ```bash
    docker start test-env
    ```

    - **コンテナに再接続：**  
    ここまでやると環境に入れる。

    ```bash
    docker attach test-env
    ```

2. **テストコードの作成**

    template Faileにテスト環境のテンプレートがあります。 
    これを複製してください。　　 
    テストコード以外のファイルを、inc / src にそれぞれ保存してください。

    test.cpp にテストコードを記載してください。  

    ※テストの例としてEX-FIFOをつけてみました。動作の確認をしてみてください。  
    .hだけのsimpleなソースです。


3. **テストの実行**

    複製したフォルダ内の test ディレクトリに移動して、exec_test.sh を実行してください。
    
    ```bash
    bash ./exec_test.sh
    ```


## その他

- テストを変更した場合は、再度ビルド（`make`）を行ってからテストを実行してください。
- コマンドプロンプトでの実行を前提としていますが、Git BashやWSLを使用する場合は、ボリュームマウントのコマンドを適宜変更してください。
