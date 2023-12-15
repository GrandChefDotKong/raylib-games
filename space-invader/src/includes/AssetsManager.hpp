#pragma once
#include "params.hpp"

class AssetsManager {

  private:
    AssetsManager() {};
    static AssetsManager* m_assetsManager;
    std::map<std::string, Texture2D> m_assets; 

  public:
    AssetsManager(AssetsManager& other) = delete;
    void operator=(const AssetsManager&) = delete;

    static AssetsManager* getInstance();
    void addAsset(std::string assetName, Texture2D asset);
    const Texture2D* getAsset(std::string assetName);

    ~AssetsManager();
};
