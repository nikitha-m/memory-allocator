# PRD-001: Minimal Userspace Allocator (malloc)

**Author:** Nikitha (with PM review from Learning PM)  
**Status:** Draft — Awaiting Approval  
**Date:** 2026-06-06  
**Target completion:** Day 14 (2026-06-19)

---

## 1. Problem Statement

There is no custom `malloc` implementation in this repository. The standard library's `malloc` is a black box. The goal is to build one from scratch to understand how dynamic memory allocation works at the systems level.

---

## 2. Goals (v1)

1. A working `malloc(size)` / `free(ptr)` / `calloc(count, size)` / `realloc(ptr, size)` implementation in C
2. Supports single-threaded allocations (thread-safety is v2)
3. Runs on **macOS only** (cross-platform considered in v2)
4. Passes basic correctness tests: no double-free, no memory leaks, no use-after-free of allocator metadata
5. Survives a stress test of 10,000 random alloc/free operations

### Non-goals

- Performance comparable to jemalloc/tcmalloc (this is a learning project)
- Thread safety (v2)
- Shrinking the heap (v2)
- Low fragmentation guarantees (v2)
- Cross-platform support (v2)
- Integration as a `LD_PRELOAD` replacement

---

## 3. Success Metrics

| Metric | Target |
|--------|--------|
| Correctness | No crashes, no leaks under stress test (10k ops) |
| Memory waste | Fragmentation not measured; we accept naive first-fit |
| Speed | Enough to complete tests in < 5s |
| Edge cases | `size=0`, `NULL`, large allocs (>1MB), alignment (16-byte) all handled |

---

## 4. Design Constraints

- **Language:** C (C99 or C11)
- **OS Interface:** `mmap()` only (no `sbrk`, deprecated on macOS)
- **Toolchain:** gcc/clang, Makefile
- **Testing:** No external test frameworks; write our own `test.c`
- **Error handling:** Return `NULL` on failure (`errno` setting optional but preferred)

---

## 5. High-Level Architecture (to be detailed in HLD)

```
┌─────────────────────────────────────┐
│         User Program (test.c)        │
├─────────────────────────────────────┤
│       Our API: malloc/free/...       │  ← test.c includes our header
├─────────────────────────────────────┤
│         Allocator Logic              │  ← malloc.c: free list, split, coalesce
├─────────────────────────────────────┤
│         OS Layer (mmap)              │  ← malloc.c directly calls mmap()
└─────────────────────────────────────┘
```

- **No OS abstraction layer** (by choice — we'll add it in v2 and feel the pain)
- Allocator manages a **linked list of free blocks** (implicit free list)
- Blocks have a **header** containing size + in-use flag

---

## 6. Deliverables

| Deliverable | Owner | Due |
|-------------|-------|-----|
| HLD document | Nikitha | Day 2 |
| LLD document | Nikitha | Day 3 |
| `malloc.c` (core allocator) | Nikitha | Day 7 |
| `malloc.h` (public API) | Nikitha | Day 4 |
| `test.c` (test harness) | Nikitha | Day 10 |
| `Makefile` | Nikitha | Day 4 |
| Retro document | Nikitha | Day 13 |

---

## 7. Timeline (14 days, 2 hr/day)

| Day | Focus |
|-----|-------|
| 1 | PRD approval + HLD teaching + start writing HLD |
| 2 | Complete HLD, submit for review, fix |
| 3 | LLD teaching + write LLD, submit for review |
| 4 | Starter code: `malloc.h`, `Makefile`, `mmap` test |
| 5 | `malloc` implementation (free list, split) |
| 6 | `free` implementation (coalesce) |
| 7 | Debug + fix malloc/free |
| 8 | `calloc` + `realloc` |
| 9 | Basic stress test |
| 10 | Edge cases + hardening |
| 11 | Thread-safety (mutex) + multithreaded test |
| 12 | Bug fixes, leak check |
| 13 | Retrospective |
| 14 | Buffer / polish / done |

---

## 8. Risks

| Risk | Mitigation |
|------|-----------|
| Underestimating complexity of coalescing | Start early, test with simple patterns first |
| `mmap` returning `MAP_FAILED` | Check return, return NULL |
| Alignment bugs | Use `max(16, sizeof(header))` alignment in block sizes |
| Stack corruption from buggy allocator | Write small, incremental tests; use a debugger |

---

## 9. Approval

**Instructions:** Read this PRD. If you accept it, reply: **"PRD Approved"**.  
If you want changes, tell me what's wrong and I'll revise.

Once approved, we move to Day 1 — I'll teach you what an HLD is and you'll start writing it.
