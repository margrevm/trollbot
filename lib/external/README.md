# External submodules

This folder contains external projects that are used by the Robot software.

More infos on GIT submodules on [devconnected.com](https://devconnected.com/how-to-add-and-update-git-submodules/) and the [official GIT page](https://git-scm.com/book/en/v2/Git-Tools-Submodules).

## Adding a submodule

```sh
git submodule add <remote_url> <destination_folder>
git submodule update --init --recursive
```

## Removing a submodule

```sh
git submodule deinit -f <submodule>
git rm -f <submodule>
```

Maybe you need to delete the relevant section from .git/config. e.g. delete these:

```sh
[submodule "path_to_submodule"]
    url = https://github.com/<destination_folder>
```

Also remove submodule from git folder:

```sh
rm -rf .git/modules/path_to_submodule
```
