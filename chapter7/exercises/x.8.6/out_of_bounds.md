The behavior is *undefined*.

Depending on the test the application and the system will behave differently.

*Global*, *Local*, and *Member* array:

* *beyond* and *before* the array may not harm much. In a large application with
  lots of objects allocated it may corrupt some data that is used by the
  application and this way lead to unexpected behavior in the application. At
  most the application will crash

* *far beyond* and *far beyond* the array will start affecting parts of memory
  that are used by other applications

*Heap*

The data may be allocated far away from the main applications stack and
therefore any write outside of array bounds will corrupt other applications
data.
