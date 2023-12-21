#pragma once
#include <string>
#include <map>
#include <iostream>

template <class T>
class AssetsManager {

  private:
    AssetsManager() {};
    static AssetsManager* m_assetsManager;
    std::map<std::string, T> m_assets; 

  public:
    AssetsManager(AssetsManager& other) = delete;
    void operator=(const AssetsManager&) = delete;

    static AssetsManager* getInstance();
    
    void addAsset(std::string assetName, T asset);
    const T* getAsset(std::string assetName);

    ~AssetsManager();
};
