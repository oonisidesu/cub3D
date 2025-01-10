
# **cub3D**

## **概要**

`cub3D` は、Wolfenstein 3D 風の2Dレイキャスティングエンジンです。このプロジェクトは、C言語を使用して、ミニマルな3Dゲームエンジンを構築することを目的としています。

## **特徴**

- **2D レイキャスティング** を用いた3Dレンダリング。
- プレイヤーの移動と視点の回転。
- テクスチャマッピングされた壁と床・天井の描画。
- `.cub` ファイル形式での設定読み込み。
- ミニマップ表示 (オプション)。
- エラーハンドリング (ファイルフォーマット、メモリ不足、無効なマップなど)。

## **画面**

<video width="640" height="360" controls>
  <source src="mp4/movie.mp4" type="video/mp4">
  Your browser does not support the video tag.
</video>

---

## **インストール**

1. **リポジトリをクローン**
   ```bash
   git clone --recurse-submodules https://github.com/yourusername/cub3D.git
   cd cub3D
   ```

2. **コンパイル**
   ```bash
   make
   ```

3. **実行**
   ```bash
   ./cub3D <マップファイル>
   ```

## **使用方法**

1. **起動**
   - `cub3D` の実行:
     ```bash
     ./cub3D map/your_map.cub
     ```
   - `map/` フォルダにある `.cub` ファイルを使用してゲームを起動できます。

2. **操作**
   - **W/A/S/D**: 移動。
   - **左右矢印キー**: 視点の回転。
   - **ESC**: ゲーム終了。

## **設定ファイル**

`.cub` ファイルは以下の要素を含みます:

- **テクスチャ設定**
  ```
  NO ./path_to_north_texture.xpm
  SO ./path_to_south_texture.xpm
  WE ./path_to_west_texture.xpm
  EA ./path_to_east_texture.xpm
  ```
- **床と天井の色**
  ```
  F 220,100,0
  C 225,30,0
  ```
- **マップ**
  ```
  111111111
  100000001
  100000001
  100P00001
  111111111
  ```
  - **1**: 壁
  - **0**: 空間
  - **P**: プレイヤースタート位置

## **依存関係**

- **MiniLibX**
  - 2Dグラフィックライブラリ。
- **libft**
  - 自作のCライブラリ。

## **テスト**

### End-to-End
- `test/e2e/runner.sh` を使用して、以下をテスト:
  - 無効なマップファイルのエラー処理。
  - マップの境界条件。
