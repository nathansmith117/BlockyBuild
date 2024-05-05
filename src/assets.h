#include "gameCommon.h"

// Will work on this more when I have assets to use.

#ifndef ASSETS_H
#define ASSETS_H

#define ASSETS_NAME_MAX 256
#define TEXTURE_ASSET_COUNT 0
#define MODEL_ASSET_COUNT 0

// List of assets.
extern const char textureAssetFiles[TEXTURE_ASSET_COUNT][ASSETS_NAME_MAX];
extern const char modelAssetFiles[MODEL_ASSET_COUNT][ASSETS_NAME_MAX];

typedef struct Assets {
    Texture textures[TEXTURE_ASSET_COUNT];
    Model models[MODEL_ASSET_COUNT];
} Assets;

void initAssets(Assets* assets);
void closeAssets(Assets* assets);

#endif
