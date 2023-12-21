#include "../AssetsManager.hpp"

template <class T>
AssetsManager<T>* AssetsManager<T>::m_assetsManager = nullptr;

template <class T>
AssetsManager<T>* AssetsManager<T>::getInstance() {
  if(m_assetsManager == nullptr) {
    m_assetsManager = new AssetsManager();
  }

  return m_assetsManager;  
}

template <class T>
void AssetsManager<T>::addAsset(std::string assetName, T asset) {
  for(const auto& asset : m_assets) {
    if(asset.first == assetName) {
      std::cout << "Asset name already used !" << std::endl;
      return;
    }
  }

  m_assets[assetName] = asset;
}

template <class T>
const T* AssetsManager<T>::getAsset(std::string assetName) {
  return &m_assets[assetName];
}

template <class T>
AssetsManager<T>::~AssetsManager() {
  for(auto asset : m_assets) {
    UnloadTexture(asset.second);
    std::cout << asset.first << " unloaded : OK !" << std:: endl;
  }
}