#include "NormalUser.h"
#include "AdminUser.h"
#include "CoAdminUser.h"
#include "CtrlCat.h"
#include "Dogorithm.h"

int main(int argc, const char** argv) {

    NormalUser dummy("Normal user");
    AdminUser admin("admin");
    CoAdminUser coadmin("CoAdmin");
    CtrlCat catgroup;
    Dogorithm doggroup;

    catgroup.registerUser(&admin);
    catgroup.registerUser(&coadmin);
    catgroup.registerUser(&dummy);
    doggroup.registerUser(&admin);
    doggroup.registerUser(&coadmin);

    admin.send("I am the boss now",&catgroup);

    return 0;
}