//
// Created by student on 12.06.23.
//

#ifndef HOTEL_REPOSITORY_H
#define HOTEL_REPOSITORY_H

#include <memory>
#include <functional>
#include "vector"
#include "algorithm"
#include "string"

template<class Model> class Repository{
    typedef std::shared_ptr<Model> ModelPtr;
    typedef std::function<bool(ModelPtr)> ModelPredicate;
protected:
    std::vector<ModelPtr> objects;

public:
    virtual ~Repository() = default;

    unsigned int size() const{
        return objects.size();
    }

    ModelPtr get(unsigned int index) const{
        if(index >= size())
            return nullptr;
        else
            return objects[index];
    }

    void add(ModelPtr object){
        if(object)
            objects.push_back(object);
    }

    void remove(ModelPtr object){
        if(object)
            objects.erase(
                    std::remove(objects.begin(), objects.end(), object)
                    , objects.end());
    }

    std::string report(){
        std::string report;
        for(int i = 0; i < size(); i++){
            report += std::to_string(i + 1) + ". " + objects[i]->getInfo() + "\n";
        }
        return report;
    }

    std::vector<ModelPtr> findBy(ModelPredicate predicate) const{
        std::vector<ModelPtr> found;
        for(unsigned int i = 0; i < size(); i++){
            ModelPtr object = get(i);
            if (object != nullptr && predicate(object)) {
                found.push_back(object);
            }
        }
        return found;
    }

    std::vector<ModelPtr> findAll() {
        return findBy([](ModelPtr m){return true;});
    }

    template<class I> ModelPtr findById(I id) const{
        std::vector<ModelPtr> foundObjects = findBy([&id](ModelPtr m){return m->getId() == id;});
        return foundObjects.empty() ? nullptr : foundObjects[0];
    }
};

#endif //HOTEL_REPOSITORY_H
