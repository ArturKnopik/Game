#pragma once
#include <map>
#include <memory>
#include <string>
#include <iostream>
namespace TGC
{
	template <typename T>
	class ResourceHandler
	{
		std::map<std::pair<std::string, std::string>, std::shared_ptr<T>> resourceList;
	public:
		ResourceHandler() = default;
		~ResourceHandler() = default;
		void addResource(std::string name, std::shared_ptr<T> resource, std::string usage = {"default"});
		std::shared_ptr<T> getResourceByName(std::string name, std::string usage);
	};

	template<typename T>
	inline void ResourceHandler<T>::addResource(std::string name, std::shared_ptr<T> resource, std::string usage)
	{
		for (auto it = resourceList.begin(); it != resourceList.end(); it++)
		{
			if (it->first.first == name && it->first.second == usage)
			{
				std::cout << "resource named: '" << name << ":" << usage << "' exist on the list!" << std::endl;
				return;
			}
		}
		resourceList.insert(std::make_pair(std::make_pair(name, usage), resource));
	}

	template<typename T>
	inline std::shared_ptr<T> ResourceHandler<T>::getResourceByName(std::string name, std::string usage)
	{
		auto findResoult = resourceList.find({ name, usage });
		if (findResoult == resourceList.end())
		{
			std::cout << "resource named: '" << name <<":"<<usage<< "' don't exist on the list!" << std::endl;
			return nullptr;
		}
		else
		{
			return findResoult->second;
		}
	}
}