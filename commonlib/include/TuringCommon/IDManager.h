#ifndef _TuringCommon_IDManager_H_
#define _TuringCommon_IDManager_H_

#include <map>
#include <string>
#include <sstream>

#include "TuringCommon/LibDefs.h"
#include "TuringCommon/RuntimeError.h"

namespace TuringCommon {
    template <class T> class IDManager {
    public:
        IDManager(std::string typeName) : LastId(-1), TypeName(typeName){}
        ~IDManager();
        T *get(TInt id);
        bool exists(TInt id);
        
        // life cycle
        TInt getNew();
        TInt insertNew(T *newItem);
        void remove(TInt id);
        
        // public so it can be iterated
        std::map<TInt,T *> Items;
    protected:
        void assertExists(TInt id);
        TInt LastId;
        std::string TypeName;
    };

    #pragma mark Methods

    template <class T>
    IDManager<T>::~IDManager() {
        for (unsigned int i = 0; i < Items.size(); ++i) {
            T *curItem = Items[i];
            delete curItem;
        }
    }

    template <class T>
    T *IDManager<T>::get(TInt id) {
        assertExists(id);
        return Items[id];
    }

    template <class T>
    bool  IDManager<T>::exists(TInt id) {
        return Items.find(id) != Items.end();
    }

    template <class T>
    TInt IDManager<T>::getNew() {
        T *newItem = new T();
        return insertNew(newItem);
    }
    
    template <class T>
    TInt IDManager<T>::insertNew(T *newItem) {
        LastId += 1;
        Items[LastId] = newItem;
        return LastId;
    }

    template <class T> 
    void IDManager<T>::remove(TInt id) {
        T *win = get(id);
        Items.erase(id);
        delete win;
    }

    #pragma mark Protected and Private Methods

    template <class T>
    void IDManager<T>::assertExists(TInt id) {
        if (!exists(id)) {
            std::ostringstream os;
            os << TypeName << " ID " << id << " does not exist.";
            TuringCommon::runtimeError(os.str().c_str());
        }
    }
}
#endif