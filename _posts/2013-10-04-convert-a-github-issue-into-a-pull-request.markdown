---
layout: post
title: "Convert a GitHub Issue into a Pull Request"
date: 2013-10-04 12:55:53 -0400
external-url: http://opensoul.org/blog/archives/2012/11/09/convert-a-github-issue-into-a-pull-request/
---

Thank you, Brandon Keepers, for this little tidbit:

```bash
hub pull-request -i 384 \
  -b bkeepers:master \
  -h bkeepers:branch-name
```
