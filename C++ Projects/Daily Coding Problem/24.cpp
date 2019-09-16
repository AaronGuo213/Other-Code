#include <iostream>
using namespace std;

class node {

    bool locked;
    int descendantsLocked = 0, value;
    node parent;

    node(node self, int val, node Parent) {
        value = val;
        parent = Parent;
        locked = false;
    }

    bool isLocked() {

        return locked;

    }

    bool areAncestorsLocked(node self) {

        if(parent == 0)
            return false;

        else
            return parent.isLocked() || areAncestorsLocked(self.parent);

    }

    bool lock() {

        if(descendantsLocked > 0 || areAncestorsLocked(self))
            return false;

    }

};