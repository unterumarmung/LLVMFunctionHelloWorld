#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"

#include "llvm/Demangle/Demangle.h"

#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

struct HelloWorld : FunctionPass
{
    HelloWorld() : FunctionPass(ID) {}
    inline static char ID = 0;
    bool runOnFunction(Function &F) override {
        errs() << "Hello: ";
        errs().write_escaped(demangle(F.getName())) << '\n';
        return false;
    }
};

[[maybe_unused]] static RegisterPass<HelloWorld> X("hello", "Hello World Pass",
                             false /* Only looks at CFG */,
                             false /* Analysis Pass */);

[[maybe_unused]] static RegisterStandardPasses Y(
        PassManagerBuilder::EP_EarlyAsPossible,
        [](const PassManagerBuilder &Builder,
           legacy::PassManagerBase &PM) { PM.add(new HelloWorld()); });
