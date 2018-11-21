/**
 * The main class contained here defines what a resource is, how it's handled,
 * mutex behavior, and dependency structure. It is supposed to be abstract
 */

class Resource : Abstract
{
        ////MUTEX BEHAVIOR////
        //TODO
        //  define an owner of a resource, where the resource can be passed off to a different owner in an atomic step
        //  should also be able to borrow resources and return them in pristine condition
        
        ////FETCH BEHAVIOR////
        //TODO
        //  resources should be able to fetch themselves upon initialization, and determine whether they are ready or not

        ////DESTRUCT BEHAVIOR////
        //TODO
        //  define how a resource cleans up after itself and destructs, as well as whether it can be destroyed or not
}
