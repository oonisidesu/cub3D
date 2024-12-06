#!/bin/bash

# 実行ファイルのパス
EXECUTABLE="./cub3D"

# マップファイルのディレクトリ
MAP_DIR="map/error"

# マップディレクトリ内の .cub ファイルをループで処理
for file in "$MAP_DIR"/*.cub; do
    if [ -f "$file" ]; then
        echo "Running: $EXECUTABLE $file"
        $EXECUTABLE "$file"
    else
        echo "No .cub files found in $MAP_DIR"
        exit 1
    fi
done