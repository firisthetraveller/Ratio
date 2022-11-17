# Unit tests changelog

12.11.12 :
- All current unit tests are subject to future changement, after we learn which unit test framework we are allowed to use.
- Added : division by zero
- Added : auto-simplify tests
- Questions : 
    - Auto-simplify at all operations ?
        -> Yes : Simplify is a private method
    - Unit Test framework -> GoogleTest
- For next time :
    - G : Check how to evaluate complex functions
        - Focused Stern-Brocot (Estimated complexity: O(2n), n: number of iterations)

17.11.12 :
- Prepared GoogleTest unit test base
- Questions :
    - Ratio<unsigned int> , Ratio<float>
        - Ratio<float> seems not to be possible, how can we restrict the available types so we don't use Ratio<float> ?
    - How to check for the existence of a method
        - Check for a private method simplify.
        - Check from "outside" that simplify is not usable.
- G : What are the expected exceptions ?
