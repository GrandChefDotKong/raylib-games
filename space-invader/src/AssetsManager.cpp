#include "./includes/AssetsManager.hpp"

AssetsManager* AssetsManager::m_assetsManager = nullptr;

AssetsManager* AssetsManager::getInstance() {
  if(m_assetsManager == nullptr) {
    m_assetsManager = new AssetsManager();
  }

  return m_assetsManager;  
}

void AssetsManager::addAsset(std::string assetName, Texture2D asset) {
  for(const auto& asset : m_assets) {
    if(asset.first == assetName) {
      std::cout << "asset name already ussed !" << std::endl;
      return;
    }
  }

  m_assets[assetName] = asset;
}

const Texture2D* AssetsManager::getAsset(std::string assetName) {
  return &m_assets[assetName];
}

AssetsManager::~AssetsManager() {
  for(auto asset : m_assets) {
    UnloadTexture(asset.second);
    std::cout << asset.first << " unloaded : OK !" << std:: endl;
  }
}