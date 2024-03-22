## Setting up the development environment

See [Env.md](Env.md).


## Provide patches

Patches for additional functions, bug fixes, etc. are accepted via pull requests.

Please note the following when submitting patches via pull request.


### Creating a related GitHub Issue

Before creating a pull request, check to see if a related GitHub Issue exists, and if not, create the Issue first.


### Coding Style

Comments in the code should be in English. Japanese is also acceptable.


### Testing (optional)

Test SPIKE-RT after applying the patch to confirm that it works.

Add tests as necessary.

See [Test.md](Test.md) for how to run tests.


We do not require rigorous testing at this time.


### Pull Request Title

The title is used as the commit name when merging, so it should be the same as [Conventional Commits](https://www.conventionalcommits.org/ja/v1.0.0/).  

English is preferred. Japanese is also acceptable.  



````

feat(cbricks/hub/light): add API for the hub built-in status light.

```


### Pull request body

Accepted in English or Japanese.