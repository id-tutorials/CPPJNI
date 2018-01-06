#include <iostream>
#include <jni.h>

int main(int argc, char *argv[]) {
    JavaVM *javaVM;
    JNIEnv *jniEnv;
    JavaVMInitArgs javaArgs;
    JavaVMOption options[1];
    options[0].optionString = "-Djava.class.path=/home/idurdyev/CLionProjects/CPP_JNI/target/jnitest-1.0-SNAPSHOT.jar";

    javaArgs.version = JNI_VERSION_1_6; //JDK version. This indicates version 1.6
    javaArgs.nOptions = 1;
    javaArgs.options = options;
    javaArgs.ignoreUnrecognized = 0;

    JNI_GetDefaultJavaVMInitArgs(&javaArgs);
    JNI_CreateJavaVM(&javaVM, (void **) &jniEnv, &javaArgs);

    jclass cls = jniEnv->FindClass("com/idurdyev/cpp/jni/jnitest/Main");
    jmethodID mid = jniEnv->GetStaticMethodID(cls, "helloFromJava", "()Ljava/lang/String;");
    jobject o = jniEnv->CallStaticObjectMethod(cls, mid);
    jstring str = static_cast<jstring>(o);

    std::cout << jniEnv->GetStringUTFChars(str, 0) << std::endl;

    return 0;
}